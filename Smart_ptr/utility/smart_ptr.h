#pragma once

namespace Wuda
{
    namespace utility
    {
        template<typename T>
        class SmartPtr
        {
        public:
            SmartPtr() : m_data(nullptr){}
            SmartPtr(T * data) : m_data(data){}
            ~SmartPtr()
            {
                if(m_data != nullptr)
                {
                    delete m_data;
                    m_data = nullptr;
                }
            }    

            T * operator->()
            {
                return m_data;
            }
            
            T & operator*()
            {
                return *m_data;
            }

        private:
            T * m_data;
        };
    }
} // namesWudapace 
