/*
This source code is part of specs, an application for
protein residue conservation scoring.
Written by Ivana Mihalek.
Copyright (C) 2007-2013 Ivana Mihalek.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see<http://www.gnu.org/licenses/>.

Contact: ivana.mihalek@gmail.com.
*/
# include "specs.h"

int output_clustering (char * base_filename,  int * int_cvg, double *clustering_score, int length){

    int ctr;
    FILE * fptr;
    char filename[BUFFLEN];
    double area_over_coverage (int * int_cvg, double * value, int no_of_res ) ;
    
    sprintf (filename, "%s.clustering", base_filename);

    fptr = efopen (filename, "w");
    if ( !fptr) return 1;
    
    fprintf ( fptr, "%%%8s%8s%12s\n", "cum res", "cvg ", "z  ");
  
    for (ctr=0; ctr < length &&int_cvg[ctr] ; ctr++ ) {
	fprintf ( fptr, "%8d%8.3lf%12.3le\n",
		  int_cvg[ctr], (double)int_cvg[ctr]/length, clustering_score[ctr]);
	
    }

    fprintf ( fptr, "\n%%  area:  %8.3lf\n", area_over_coverage(int_cvg, clustering_score, length) );
    fclose (fptr);
    
    return 0;
}
