setwd("C:\\Users\\x00130016\\SC")

athletes <- read.table("athletes.txt", header=TRUE, sep=",")

# change the sex field to be M/F

athletes$Sex <- factor(as.factor(athletes$Sex), labels=c("M","F"))

#find the minumim hight
print(mean(athletes$Ht))


