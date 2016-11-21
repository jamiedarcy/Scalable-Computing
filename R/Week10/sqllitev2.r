setwd('C:/Users/x00130016/SC/week10')




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





#write function

getRows <- function(resHT,numrows)
{
	d <- dbFetch(resHt,n=numrows)
	mean(d$Ht)

}

#print(mean(sapply(rep((count / chunckSize), chunckSize), function(i) getRows(resHT,i))))

#or 

print(mean(sapply(rep((count / chunckSize), chunckSize), FUN=function(i) 
	{
	getRows(resHT,i)))
	})