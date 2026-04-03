class Student:
    def __init__(self, id:int, name:str, study_group: str):
         self.__id = id
         self.name = name
         self.study_group = study_group

    def get_id(self) -> int:
        return self.__id

    def set_id(self, id:int):
        if id <= 0:       raise Exception("id <= 0")
        if id >  999_999: raise Exception("id > 999'999")
        self.__id = id

    def __str__(self):
        return f"ID = {self.__id}, {self.name}, {self.study_group}"



s1 = Student(1, "Ivanov I. A. ", "123")

s1.set_id(2)
# print(s1.name)
# print(s1.study_group)
