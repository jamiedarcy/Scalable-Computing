setwd('C:/Users/jdarcy/Documents/GitHub/Scalable-Computing/R')

file <- file.path("SC-Lab2","mpstat.txt")
mydata <- read.table(file, 
                     header = TRUE, 
                     sep="\t")

colnames(mydata)
summary(mydata)


str(mydata)
print("hello")
head(mydata)


mean(mydata%Xidle)
mean(mydata['%idle'])
mean(mydata$%idle)






#Plot the idle time of this CPU
plot(mydata)
#Plot the busy time of this CPU
plot()
#Find the min, max and mean of the data
min(mydata)
max(mydata)
mean(mydata$idle)


# scatter plot  


#Use a boxplot 
boxplot()


















#range(mydata)
#diff(range(mydata)
#summary(mydata)
#summary(mydata)