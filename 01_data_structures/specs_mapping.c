# include "specs.h"
int  struct_almt_mapping (Protein * protein, Alignment * alignment,
			  int * prot2almt, int * almt2prot){
    int prot_pos, almt_pos;
    char * pdbseq = alignment->pdbseq;
    Residue * prot_seq;
    
 
    /*compare */
    prot_pos = 0;
    prot_seq = protein->sequence;
    for (almt_pos=0; almt_pos < alignment->length; almt_pos++ ) {
	if ( pdbseq [almt_pos] == '.' ) {
	    almt2prot [almt_pos] = -1;
	} else {
	    if ( prot_seq[prot_pos].res_type_short ==  pdbseq [almt_pos] ) {
		prot2almt[prot_pos] = almt_pos;
		almt2prot[almt_pos] = prot_pos;
	    } else {
		fprintf (stderr, "Structure/alignment mismatch,\n");
		if(prot_seq[prot_pos].res_type_short){
		  fprintf (stderr, "\t structure: pdbid %s  value %c \n",
			   prot_seq[prot_pos].pdb_id,  prot_seq[prot_pos].res_type_short);
		  fprintf (stderr, "\t alignment: pos %d  value %c \n",   almt_pos,  pdbseq[almt_pos]);
		}
		else{
		  fprintf (stderr, "\t The chain specified doesn't exist\n");
		}
		
		return 1;
	    }
	    prot_pos++;
	}
    }
    return 0;
}
