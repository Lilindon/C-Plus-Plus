## 运算符重载

#### 友元函数重载  
#### 成员函数重载   
* 运算符重载 可分为友元函数重载  和  成员函数重载
* 前向++ 和 后向++ 可分为友元和成员重载  
### 运算符重载<<  调用者应作为成员函数，参数提供者应作为友元函数  
    class Email;  
    class Sender  
    {  
    public:  
        Sender(string addr)  
            :m_addr(addr){};
        Sender& operator<<(const Email &email);   // 成员
    private:  
        string m_addr;  
    };

    class Email
    {
    public:
        Email(string title,string context)
            :m_title(title),m_context(context){};
        friend Sender& operator<<(const Email &email); // 友元
    private:
        string m_title;
        string m_context;
    };

    Sender& Sender::operator<<(const Email &email)
    {
        cout<<this->m_addr;
        cout<<email->m_title;
        cout<<email->m_context;
    }

### 智能指针 解决内存泄露所提出的一种具有类似指针功能的对象  
    内存泄露：new后没有delete，或delete之前发生异常 提前结束函数运行
      
    auto_ptr<类型> 变量名<new 类型>   
    auto_ptr<T> t(new T);  
    t->func();  
    (*t).func();
