#ifndef EATMS_MODEL_PERSON_H_
#define EATMS_MODEL_PERSON_H_

#include <string>

namespace eatms
{
    namespace model
    {
        class Person
        {
            public:
                Person (const std::string &name);
                virtual ~Person () = 0;

                void        setAge(const int &age);
                void        setName(const std::string &name);

                std::string getName();
                int         getAge();

            private:
                /* data */
                std::string name_;
                int age_;
        };
    } /*  model */
} /* eatms */

#endif /* EATMS_MODEL_PERSON_H_ */
