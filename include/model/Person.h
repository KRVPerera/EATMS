#ifndef EATMS_MODEL_PERSON_H_
#define EATMS_MODEL_PERSON_H_

#include <string>

#ifndef EATMS_EMPLOYEE_MIN_AGE
#define EATMS_EMPLOYEE_MIN_AGE 18
#endif

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

                const std::string getName() const;
                int         getAge();

            private:
                /* data */
                std::string name_;
                int age_;
        };
    } /*  model */
} /* eatms */

#endif /* EATMS_MODEL_PERSON_H_ */
