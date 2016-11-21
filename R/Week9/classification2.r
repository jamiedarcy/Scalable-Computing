setwd("C:\\Users\\x00130016\\SC")

tc2 <- read.table("textClassification2.txt", header=TRUE, sep="\t")

#print(tc2)

print(levels(tc2$classifier))





computeAccuracy <- function(alldata)
{
	correct <- nrow(subset(alldata, classification=="correct"))
	correct / nrow(alldata)

}

print(by(tc2, tc2$classifier, computeAccuracy))

