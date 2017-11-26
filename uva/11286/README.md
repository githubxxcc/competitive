> How to make complex data struct of map key?
- 1. Encode them into some sort of class (string)
- 2. Provide your own hash class template.
- 3. Use std::map because more containers support the comp operators. In this case, no need of supplied your own hash template. 





