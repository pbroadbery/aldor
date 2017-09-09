#ifndef _TTABLE_H_
#define _TTABLE_H_
#include "cport.h"
#include "ostream.h"
#include "list.h"

#define TSet(Type) Type##TSet
#define TSetIter(Type) Type##TSetIter
#define DECLARE_TSET(Type)			\
	typedef struct Type##_TSet {		\
		Type##List lst;			\
	} *TSet(Type);				\
	typedef Type##List Type##TSetIter;	\
	TSetOpsStruct(Type);			\
	extern struct TSetOpsStructName(Type)	\
                 const *TSetOps(Type)		\


#define CREATE_TSET(Type)					\
struct TSetOpsStructName(Type) const *TSetOps(Type) =		\
	(struct TSetOpsStructName(Type) const *) &ptrTSetOps

#if 0
	; /* for editor indentation */
#endif

#define tsetCreate(Type) (TSetOps(Type)->Create)
#define tsetEmpty(Type) (TSetOps(Type)->Create)
#define tsetFree(Type) (TSetOps(Type)->Free)
#define tsetAdd(Type) (TSetOps(Type)->Add)
#define tsetRemove(Type) (TSetOps(Type)->Remove)
#define tsetMember(Type) (TSetOps(Type)->Member)
#define tsetIsEmpty(Type) (TSetOps(Type)->IsEmpty)
#define tsetIter(Type) (TSetOps(Type)->Iter)
#define tsetIterNext(Type) (TSetOps(Type)->IterNext)
#define tsetIterElt(Type) (TSetOps(Type)->IterElt)
#define tsetIterHasNext(Type) (TSetOps(Type)->IterHasNext)

#define TSetOps(Type) Type##_tsetPointer
#define TSetOpsStructName(Type) Type##_tsetOpsStruct

#define TSetOpsStruct(Type)				\
struct TSetOpsStructName(Type) {			\
	TSet(Type) (*Create) (void);			\
	void 	   (*Free)   (TSet(Type));		\
	void 	   (*Add)    (TSet(Type), Type);	\
	void 	   (*Remove) (TSet(Type), Type);	\
	Bool 	   (*Member) (TSet(Type), Type);	\
	Bool 	   (*IsEmpty)(TSet(Type));		\
	TSet(Type) (*Empty)(void);			\
	TSetIter(Type)	(*Iter)(TSet(Type));		\
	TSetIter(Type)	(*IterNext)(TSetIter(Type));		\
	Type		(*IterElt)(TSetIter(Type));		\
	Bool 		(*IterHasNext)(TSetIter(Type));		\
}
#if 0
	; /* for editor indentation */
#endif

DECLARE_TSET(Pointer);

extern const struct TSetOpsStructName(Pointer) ptrTSetOps;

#endif