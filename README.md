Our web app analyzes U.S. Census demographics data to deliver targeted advice for small businesses looking to expand.

The owner writes a paragraph describing their business, and enters the existing location(s).  Using machine learning techniques (for now, we use locality-sensitive hashing followed by singular value decomposition) the app determines the regions within Delaware that are most similar to the locations where the business has already succeeded.  It then uses natural language processing to order the viable regions according to the owner's specific circumstances.

The underlying data consists of over 400 features, consisting of various combinations of age, race, and gender, allowing the algorithm to extract real meaning.

The end result is a list of 10 regions, corresponding to U.S. Census Bureau tracts, which the owner can then explore further.

Running the development server

bash build.sh 

(optional) bash offline.sh

##Challenge #1: Open Source Target Marketing Solution (Open Data Delaware)


**Solve For:** Local retail businesses that want to better understand local market expansion but lack access to existing business intelligence tools.


**Example Solution Direction:** Create a web app to inform local business expansion based on open data publicly available trends.


**Use-Case Overview:** Imagine that you are a retailer and are looking to grow your business by adding a new location. How could you make sure that you are choosing the optimal location for your expansion?  You would already have a strong idea of who your target market is, particularly their demographic information. Create a tool that would allow for a small business to identify a location to expand based upon local demographic. Points for making something that could be shared with other communities with their own data and resources.


**Possible Technical Needs:** multiple data source integration; machine learning;  database management; mapping; scoring and charting. 


Here's some initial data sets to back it up:

[Census Housing Units link](http://opendata.firstmap.delaware.gov/datasets/0d2ebba69346409aaf0e7f2d2291c14f_0?mapSize=map-maximize)

[Census Block Groups link] (http://opendata.firstmap.delaware.gov/datasets/6c95a0786d3e4b46a473ec32004b47ba_0?mapSize=map-maximize)

[Census Tracts link] (http://opendata.firstmap.delaware.gov/datasets/7c4f8cbac54a4e8686d104aefdcdf66e_1?mapSize=map-maximize)

[CitySDK link] (https://uscensusbureau.github.io/citysdk/)


**Presenting Subject Matter Expert:** 
David Ginzberg, Open Data Delaware, david@zipcodewilmington.com
