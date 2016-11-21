setwd("C:\\Users\\x00130016\\SC")

tc1 <- read.table("textClassification1.txt", header=TRUE, sep="\t")

print(tc1)
#using the tc1 dataset
#compute the accuracy of the classification algorith
#use a nrow and your own function

#print(NROW(tc1$classification == "correct"))



computeAccuracy <- function(alldata)
{
	correct <- nrow(subset(alldata, classification=="correct"))
	correct / nrow(alldata)

}

print(computeAccuracy(tc1))










