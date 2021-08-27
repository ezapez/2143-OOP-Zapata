## A05
- Name: Edgar Zapata
- Date: 25 Aug 2021 
- Class: 2143 OOP

## Definitions

### Abstraction
> To define this to a non-programmer lets think about how we use a social media app like twitter.
> For example, regular users on the app are allowed to tweet, dm, and view other functions the app allows to be seen for the user. 
> However the user does not know how each function they are using works. 
> This is basically what abstraction is it allows the essential information to be viewed, but hides the irrelevant details from the user.

><img src =https://www.sitesbay.com/cpp/images/real-life-example-of-abstraction-in-cpp.png>



### Attributes / Properties
> Lets start with Properties and continue using  twitter for an example. 
> Properties are describing the users for their username, email, phone#, and profile image.
> Pretty much  he characteristics of ther users basic twitter information.
> Attributes is additional information about the user. 
> for example, username: ezapez, email:johndoe@gmail.com, phone#:940-642-*****, and etc.

### Class 
> Classes are the main blueprint or plan of your code. What I mean is once you want to write a project in any programming languaged having classes will help break down and create a more smooth  code. Class are a template for creating objects that house attrubutes and methods to be used at any time in the code. 
><img src = https://www.101computing.net/wp/wp-content/uploads/Superhero-Class.png>

## Class Variable 
> A class variable is any type of varable that is declared within the class 
> Main ones are Static Variable, instance variable, and local variable. 
><img src=https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png>

## Composition
> Basic term is building complex objects from smaller ones 
> The main use in c++ is to make it more easier and simple to input complex classes in our class.

## Constructor
> A Member function that has the same name as the class. Used to initialize values, is automatically executed, but can not house return types or void. We also have a Default constructor which no arguments are passed.
> example: 
class student{
    public:
        student();
};

## Encapsulation
> Holds all the data together and the funtion that are using them 
> For example, a function needing data from another funciton can't directly access them, but 
> can request for that data from that function. Which can then be used by the first function. 
><img src= https://media.geeksforgeeks.org/wp-content/uploads/Encapsulation-in-C-1.jpg>


## Friends
>Are functions of a class define outside the scope of it. Which have the right to access all the
> private and protected members of the class.
> However they are not member functions, its used for templates.

## Inheritence
> The most important aspect of OOP, inheritence is used to reduce duplactions of methods that the classes will be using. 
> For example, if we have three classes that are similar and each have the same methods within them. We would want to reduce this to lessen any type of error or confusion so we use inheritence to write one class that will house the methods the other classes will be using.

><img src= https://media.geeksforgeeks.org/wp-content/uploads/inheritance2.png>

## Instance Variables
> Go along with objects are created when the object is made and destroyed when the object is destroyed. Its decleard within the classes is a non-static variable. 

## Member Variable
>   a Variable inside a class its used for certain object and can also be used by all the methods within the class

## Method
> The basic term is its a function that belongs to class it can either be inside or outside
> is when wanting to be used it put in the main with the class being called in there to. For it to be able to be used. 


## Multiple Inheritance
>  allows a class to get other classes members. It a main feature in c++ they must be place in order for it to work. 

## Object 
> A can be anything a programmer wants it to be like a chair, car, and can. Its entity that  has 
> state and behavior. can be any data type that has a function.
> Example: Car cr1; // object of car

## Overloading
>Allows you to define the same methods within it each other. You can have a void method that prints out different things, but the complier will chose what is appropriate. 

## Polymorphism
>  Basic term is to many forms. In c++ its usally happens when many of our class have the same Inheritance  and polymorphism occurs which allows us to do many differnet task with these Multiple Inheritance. 
><img src= https://miro.medium.com/max/1276/1*cFSJ95jyw-ACiWaIRxAbbg.jpeg>

## Public/Private/Protected
> all these are used within a class 
> Public: allows its variables or methods be access directly  
> Private: hides information that only allows its variables or methods with permisson.
> you can not access it directly it has to be accessed within the classes or placed into a function
> that will allow you to use it
>Protected: while almost the same as Private but only differnece is that its only allowed to be access in the class. Unlike Private which allows to be use outside the class thourgh anohter function linking to it. 

## Static
> outside class its allocates space ina program. Only gets allcaoted once. Doesn't need to be called mutiple times
> Inside the class Only need to be called once are shared by objects can not be inside a contructors 




## Virtual
>  A member function that is declered inside the class it ensure the right function is called for the object. There are rules when using virtual functions cannot be static, needs to be access with pointes or refernece. Can have a dectructor, but no constructor. 
