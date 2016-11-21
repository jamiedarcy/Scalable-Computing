setwd('C:/Users/x00130016/SC/week10')


setwd("C:\\Users\\x00130016\\SC")

athletes <- read.table("athletes.txt", header=TRUE, sep=",")

# change the sex field to be M/F

athletes$Sex <- factor(as.factor(athletes$Sex), labels=c("M","F"))

#find the minumim hight
print(mean(athletes$Ht))


library(RSQLite)
con <- dbConnect(RSQLite::SQLite(), dbname="athletes.sqlite")

# Get the number of rows in database
cnt <- dbSendQuery(con, "Select count(*) from athletes_table;")
countArray <- dbFetch(cnt) #This returns value but text
count <- countArray[1,] #Strip out text and just have the value

#dbClearResult(dbListResults(con)[[1]])
resHt <- dbSendQuery(con, "Select Ht from athletes_table;")


print(count)
chunckSize <-50




#place this code in a function 
#that is called with the parameter numrows


#write function

getRows <- function(numrows)
{
	d <- dbFetch(resHt,n=numrows)
	mean(d$Ht)

}


#m1 <- getRows(50)
#m2 <- getRows(50)
#m3 <- getRows(50)
#m4 <- getRows(50)

#print((m1+m2+m3+m4)/4)
#print(sapply(50, FUN = getRows))

#this
#print(mean(sapply(c(50,50,50,50), FUN = getRows)))
#this is better
#v1 <- c(50,50,50,50)
#print(mean(sapply(v1, FUN = getRows)))



print(mean(sapply(rep((count / chunckSize), chunckSize), FUN = getRows)))

