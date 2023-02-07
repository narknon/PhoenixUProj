#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackBehaviorSorting.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_InsertBehaviorAfter.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable)
class UBTT_Camera_InsertBehaviorAfter : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackBehavior> BehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehavior>> InsertAfterBehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting InsertAfterBehaviorSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReuseBehaviorOnReactivate;
    
    UBTT_Camera_InsertBehaviorAfter();
};

