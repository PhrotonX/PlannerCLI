# PlannerCLI
- A school project that allows managing events in a monthly calendar while in a CLI environment.

## Git Semantics
- Always open a open request that merges into **dev** branch (if availabl0).
- Refrain from directly making or merging changes into main branch.

## Code Semantics
- Use namespace for each classes.
Example:
```cpp
namespace PlannerCLI
```
- Use Capital letters for the first letter of the class and function names.
Example:
```cpp

class ClassName{
	public:
	void FunctionName();
};

```

- Use hungarian notation for member variables
```cpp
#define APP_VERSION "v0.1.0" //Use capitals for macro definitions

class ClassName{
	public:
		int m_nNumber;
		std::string m_strWord;
		const char* m_pcstrWord; //or m_lpcstrWord;
		float m_fDecimal;
		double m_dDecimal;
		bool m_bFlag;
		
		static int s_nCount;
		inline static const int COUNT = 10; //Use capitals for constants.
}
```

- Always document the code with doxygen syyntax
```cpp
class ClassName{
	public:
	/**
		\details A function that adds two numbers.
		\remarks This function is not yet implemented.
		
		\param a The first value.
		\param b The second value.
		\return int The added value.
	*/
	int Add(int first, int second);
};

```

- Always implement functions in implementation file if the body of the function takes more than
3 lines of code.
