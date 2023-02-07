#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "DynamicObject_Interface.generated.h"

class AActor;

UINTERFACE(MinimalAPI)
class UDynamicObject_Interface : public UInterface {
    GENERATED_BODY()
};

class IDynamicObject_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION()
    virtual void DOUpdateParents() PURE_VIRTUAL(DOUpdateParents,);
    
    UFUNCTION()
    virtual void DOUpdateChildren() PURE_VIRTUAL(DOUpdateChildren,);
    
    UFUNCTION()
    virtual void DOUpdate() PURE_VIRTUAL(DOUpdate,);
    
    UFUNCTION()
    virtual void DOUnregisterWithDOManager(AActor* DynamicObject) PURE_VIRTUAL(DOUnregisterWithDOManager,);
    
    UFUNCTION()
    virtual void DOSetup() PURE_VIRTUAL(DOSetup,);
    
    UFUNCTION()
    virtual void DOSetDynamicObjectRegistered(bool inRegistered) PURE_VIRTUAL(DOSetDynamicObjectRegistered,);
    
    UFUNCTION()
    virtual void DORequestActivation(AActor* inRequestingActor) PURE_VIRTUAL(DORequestActivation,);
    
    UFUNCTION()
    virtual void DORemoveParentActor(AActor* InParent) PURE_VIRTUAL(DORemoveParentActor,);
    
    UFUNCTION()
    virtual void DORemovedAsParent(AActor* inChild) PURE_VIRTUAL(DORemovedAsParent,);
    
    UFUNCTION()
    virtual void DORemovedAsChild(AActor* InParent) PURE_VIRTUAL(DORemovedAsChild,);
    
    UFUNCTION()
    virtual void DORemoveChildActor(AActor* inChild) PURE_VIRTUAL(DORemoveChildActor,);
    
    UFUNCTION()
    virtual void DORegisterWithDOManager(AActor* DynamicObject) PURE_VIRTUAL(DORegisterWithDOManager,);
    
    UFUNCTION()
    virtual bool DOIsActive() PURE_VIRTUAL(DOIsActive, return false;);
    
    UFUNCTION()
    virtual bool DOHasParent() PURE_VIRTUAL(DOHasParent, return false;);
    
    UFUNCTION()
    virtual bool DOHasChildren() PURE_VIRTUAL(DOHasChildren, return false;);
    
    UFUNCTION()
    virtual bool DOHasActivationRequest() PURE_VIRTUAL(DOHasActivationRequest, return false;);
    
    UFUNCTION()
    virtual bool DOGetDynamciObjectRegistered() PURE_VIRTUAL(DOGetDynamciObjectRegistered, return false;);
    
    UFUNCTION()
    virtual void DODestroyed() PURE_VIRTUAL(DODestroyed,);
    
    UFUNCTION()
    virtual bool DODeactivationCheck(FVector Pos) PURE_VIRTUAL(DODeactivationCheck, return false;);
    
    UFUNCTION()
    virtual void DODeactivate() PURE_VIRTUAL(DODeactivate,);
    
    UFUNCTION()
    virtual void DOCleanup() PURE_VIRTUAL(DOCleanup,);
    
    UFUNCTION()
    virtual bool DOAllowsAutoActivation() PURE_VIRTUAL(DOAllowsAutoActivation, return false;);
    
    UFUNCTION()
    virtual bool DOAllowAddAsParent(AActor* inChild) PURE_VIRTUAL(DOAllowAddAsParent, return false;);
    
    UFUNCTION()
    virtual bool DOAllowAddAsChild(AActor* InParent) PURE_VIRTUAL(DOAllowAddAsChild, return false;);
    
    UFUNCTION()
    virtual bool DOAddParentActor(AActor* InParent) PURE_VIRTUAL(DOAddParentActor, return false;);
    
    UFUNCTION()
    virtual void DOAddedAsParent(AActor* inChild) PURE_VIRTUAL(DOAddedAsParent,);
    
    UFUNCTION()
    virtual void DOAddedAsChild(AActor* InParent) PURE_VIRTUAL(DOAddedAsChild,);
    
    UFUNCTION()
    virtual bool DOAddChildActor(AActor* inChild) PURE_VIRTUAL(DOAddChildActor, return false;);
    
    UFUNCTION()
    virtual bool DOActivationCheck(FVector Pos) PURE_VIRTUAL(DOActivationCheck, return false;);
    
    UFUNCTION()
    virtual void DOActivate() PURE_VIRTUAL(DOActivate,);
    
};

