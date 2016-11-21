

library(RSQLite)
con <- dbConnect(RSQLite::SQLite(), dbname="athletes.sqlite")
cnt <- dbSendQuery(con, "Select count(*) from athletes_table;")
dbFetch(cnt)
dbClearResult(dbListResults(con)[[1]])
resHt <- dbSendQuery(con, "Select Ht from athletes_table;")
d <- dbFetch(resHt,n=10)


print(d)