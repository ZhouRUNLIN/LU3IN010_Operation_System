# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/times.h>
# include <time.h>
# include <unistd.h>
#include "lanceCommande.h"

void lanceCommande(char* commande){
    int status = system(commande);
    
    if (-1 == status){       
        printf("system error!");
        return;
    }
    else{ 
        if (WIFEXITED(status)){
            if (0 != WEXITSTATUS(status)){
                printf("run shell script fail, script exit code: %d\n", WEXITSTATUS(status));
                return;
            }       
        }
    }
    // les codes precedent peuvent renvoyer un message d’erreur si la commande n’a pu être exécutée correctement.

    time_t start, end;
    time(&start);
    system(commande);
    time(&end);
    printf("Command : %s\nTime for execution : %ld\n", commande, end-start);
}

void lanceCommandeNew(char *commande){
    int status = system(commande);
    
    if (-1 == status){       
        printf("system error!");
        return;
    }
    else{ 
        if (WIFEXITED(status)){
            if (0 != WEXITSTATUS(status)){
                printf("run shell script fail, script exit code: %d\n", WEXITSTATUS(status));
                return;
            }       
        }
    }
    // les codes precedent peuvent renvoyer un message d’erreur si la commande n’a pu être exécutée correctement.
    
    clock_t start, end;
    typedef struct tms TMS;
    TMS start2, end2;
    struct timeval debut, fin;
    
    
    gettimeofday(&debut, NULL);
    times(&start2);
    system(commande);
    gettimeofday(&fin, NULL);
    times(&end2);

    long int tick_per_sec = sysconf(_SC_CLK_TCK);
    long int delt_u = fin.tv_usec - debut.tv_usec;
    long int delt_s = fin.tv_sec - debut.tv_sec;
    double temps_total = delt_s + delt_u*1./CLOCKS_PER_SEC;
    printf("Commande : %s\n", commande);
    printf("Temps total: %.6lf\n", temps_total);
    printf("Temps utilisateur: %.6lf\n", (double)(end2.tms_utime - start2.tms_utime)/tick_per_sec);
    printf("Temps système: %.6lf\n", (double)(end2.tms_stime - start2.tms_stime)/tick_per_sec);
    printf("Temps utilisateur fils: %.6lf\n", (double)(end2.tms_cutime - start2.tms_cutime)/tick_per_sec);
    printf("Temps système fils: %.6lf\n", (double)(end2.tms_cstime - start2.tms_cstime)/tick_per_sec);
    
}