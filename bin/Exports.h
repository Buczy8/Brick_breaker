#define COMPONETS_EXPORTS

#ifdef COMPONETS_EXPORTS
#define COMPONETS_API __declspec(dllexport)
#else
#define COMPONETS_API __declspec(dllimport)
#endif