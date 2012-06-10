# include "specs.h"
# include <time.h>
   /* echo options to the log file*/
int logger (Options * options, int mode, char *msg )  {
    
    char filename[LONGSTRING];
    int score_ctr;
    FILE * fptr;
    sprintf ( filename, "%s.log", options->outname);

    switch ( mode) {
    case INTRO:
    {
	fptr = efopen ( filename, "w");
	time_t    time_now;
	time(&time_now);     /* get time in seconds */
	fprintf (fptr, "\n");
	fprintf (fptr, "  SPECS version %s.\n", VERSION);
	fprintf (fptr, "  by Ivana Mihalek, 2007\n");
	fprintf (fptr, "  File produced on %s", asctime(localtime(&time_now)));
	fprintf (fptr, "\n");
	fprintf (fptr, "  Options:\n");
	if (options->chain)           fprintf (fptr, "  \t pdb chain:              %c\n", options->chain);
	if (options->almtname[0])     fprintf (fptr, "  \t alignment  file:        %s\n", options->almtname);
	if (options->refseq_name[0])  fprintf (fptr, "  \t refseq  name:           %s\n", options->refseq_name);
	if (options->scorename[0])    fprintf (fptr, "  \t score file:             %s\n", options->scorename);
	if (options->pdbname[0])      fprintf (fptr, "  \t pdb file:               %s\n", options->pdbname);
	if (options->pdbseq_name[0])  fprintf (fptr, "  \t pdb seq name:           %s\n", options->pdbname);
	if (options->max_gaps)     fprintf (fptr, "  \t max fraction of gaps:   %4.2lf\n", options->max_gaps);
	fprintf ( fptr, "  \t residue scoring method");
	if (options->number_of_methods > 1 ) fprintf ( fptr, "s");
	fprintf ( fptr, ": ");
	for (score_ctr=0; score_ctr < options->number_of_methods; score_ctr++ ) {
	    fprintf (fptr, " %s", options->method_name[score_ctr]);
	}
	fprintf ( fptr, "\n");
	
	switch ( options->tree_method) {
	case UPGMA:
	    fprintf ( fptr, "  \t tree building method:   UPGMA\n");
	    break;
	case CONSENSUS_UPGMA:
	    fprintf ( fptr, "  \t tree building method:   consensus UPGMA\n");
	    break;
	case NEIGHBOR_JOINING:
	    fprintf ( fptr, "  \t tree building method:   neighbor joining\n");
	    break;
	}
	fclose (fptr); 
    }
    break;
    case WARN:
    {
	fptr = efopen ( filename, "a");
	fprintf (fptr, "  Warning:\n");
	fprintf (fptr, "  \t %s\n", msg);
	fclose (fptr);
    }
    break;
    case STATUS:
    {
	fptr = efopen ( filename, "a");
	fprintf (fptr, "  Status:\n");
	fprintf (fptr, "  \t %s\n", msg);
	fclose (fptr);
    }
    break;
    case NOTE:
    {
	fptr = efopen ( filename, "a");
	fprintf (fptr, "  Notes:\n");
	fprintf (fptr, "  \t Remember that the results will depend on the input sequence selection,\n");
	fprintf (fptr, "  \t as well as the alignment quality and proportion of gaps in the alignment.\n");
	fclose (fptr);
    }
   
    }


    return 0;
}
 
