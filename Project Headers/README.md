# Tools
Here is some features which are useful for coding and it will save your time. 

 
1 - Screan :


    1 - Operator << : Show your text.
  
    2 - operator == : shows you massages.
  
    3 - operator || : shows your Error texts.
  
    4 - Input(): It will recevie the inputs and if there is a wrong input then your program will not crash.
  
  
  
2 - File :


    1 - Constructor : it will open file in contidion that you choose and there is no need to be check if file exist.
  
    2 - operator <<: it saved data in file in non-binary mode.
  
    3 - operator >>: it reads data and put it in opbject.
  
    4 - operator <<= : this operator is write to save data in binary mode in specific location of file but this is specialy for classes that 
      have a function called Get_ID() and that return the location.
      
    5 - operator <<= : this operator is doing the same as number 4 but in this case the object that have no Get_ID() function can be in a 
      pair wich the pair contains the object data and the location in file.
      
    6 - operator >>= : reads data of a specific location of file and the location will be clearify by Get_ID90 function.
  
    7 - operator >>= : this contains a std::pair that the object does not have a Get_ID() function and the pair contains the location of
      data in file.
       

