#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameEventEndDelegateDelegate.h"
#include "GameEventStartDelegateDelegate.h"
#include "NPC_Manager.generated.h"

class AActor;
class APerceptionPoint;
class UNPC_Component;
class UNPC_PerceptionUpdate;
class UNPC_QBUpdate;

UCLASS(Blueprintable)
class UNPC_Manager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> NPCList;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<APerceptionPoint>> PerceptionPointList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UNPC_QBUpdate*> QBUpdatePtrArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UNPC_PerceptionUpdate*> PerceptionUpdatePtrArray;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UNPC_Component>> NPCComponentList;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameEventStartDelegate GameEventStartDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameEventEndDelegate GameEventEndDelegate;
    
public:
    UNPC_Manager();
};

