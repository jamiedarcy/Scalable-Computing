setwd('C:/Users/x00130016/SC/week11')
library(foreach)
library(doParallel)


clu <- makePSOCKcluster(4)
tc2 <- read.table("textClassification2.txt", header=TRUE, sep="\t")
#clusterExport(clu, 'tc2') 
#clusterExport(clu, 'computeAccuracy')
clusterExport(clu, c('tc2','computeAccuracy')) 
registerDoParallel(clu)


#levels(tc2$classifier)

computeAccuracy <- function(alldata)
{
	correct <- nrow(subset(alldata, classification=="correct"))
	correct / nrow(alldata)

}
#foreach(i=1:3) %do% {computeAccuracy(i)}
#foreach(i=1:3) %dopar% {computeAccuracy(i)}


foreach(i=levels(tc2$classifier)) %dopar% {computeAccuracy(tc2[tc2$classifier==i,])}
#foreach(i=1:3) %do% {computeAccuracy(i)}

timeResult <- system.time(sqrt(5)) 

print(timeResult)


#do parallel alternitave to this

#parLapply(clu, levels(tc2$classifier), function (cond) 
#	{ 
#	computeAccuracy(tc2[tc2$classifier==cond,])})
#	
#	print('i am finished')
	


#by(tc2, tc2$classifier, parLapply(clu, 1:3, computeAccuracy))



#invoke the compute function 16 time on 4 process - each one will run 4 
#parLapply(clu, 1:16, computeAccuracy)


#stopCluster(clu)


