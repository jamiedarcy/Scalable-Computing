setwd('C:/Users/x00130016/SC/week11')
library(parallel)
clu <- makePSOCKcluster(4)



compute <- function(id)
{
	mean(c(1:400)/id)
	
}

print(compute(20))


clusterExport(clu, c('compute')) 


v <-c(1:100)
print(v)

clusterExport(clu, c('v', 'compute'))


#invoke the compute function 16 time on 4 process - each one will run 4 
parLapply(clu, 1:16, compute)


stopCluster(clu)