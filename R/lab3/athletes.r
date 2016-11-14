setwd("C:\\Users\\x00130016\\SC")

athletes <- read.table("athletes.txt", header=TRUE, sep=",")

# change the sex field to be M/F

athletes$Sex <- factor(as.factor(athletes$Sex), labels=c("M","F"))

#find the minumim hight
print(min(athletes$Ht))

#find the row with the min hight

print(athletes[athletes$Ht == min(athletes$Ht),])


print(athletes[athletes$Sport == "gym",])



print(athletes[athletes$Sport == "gym",])
print(subset(athletes, Sport=="gym" & Sex=="F"))


#assign the output from a varible and output the hight in a boxplot

athheight <- subset(athletes, Sport=="gym" & Sex=="F")
#print(athheight)
boxplot(athheight$Ht)

#do the above in 1 step
with(subset(athletes, Sport=="gym" & Sex=="F"),boxplot(athheight$Ht))

#show outliers 
#with(subset(athletes, boxplot(Ht~Sport+Sex)))





#write function

displayHist <- function(data)
{
	hist(data)
	mean(hist)

}


displayHist(athletes$Ht)

print(displayHist(athletes$Ht))






















































