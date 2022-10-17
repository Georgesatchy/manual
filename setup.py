from distutils.core import setup, Extension

def main():
    setup(name="testmodule",
          description="Python test module coded in C++",
          ext_modules=[Extension("testModule", ["testmodule.cpp"])])

if __name__ == "__main__":
    main()