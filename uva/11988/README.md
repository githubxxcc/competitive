
### How to convert list of char to string? 
Use std::string 's initializer:
```
string s(list.begin(), list.end());
```

### Which iterator position does list.insert(itr, data) returns?
Original position +1 (Meaning *itr unchanged )

### How to read a line character by char?
```
while(getline(cin, line){
    istringstream iss(line);
    while(iss.get(c){}
}
```

One thing to take note is:

```
while(iss.good()){
    iss >> c;
    ....
}
```
The above code will actually one additional loop, and the last char being used in the body twice. Because the iss.good() returns the condition of last read. So at the last iteration. 


### Which lib to include for istringstream
<sstream>

