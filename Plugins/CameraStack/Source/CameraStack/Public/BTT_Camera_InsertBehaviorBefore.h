#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackBehaviorSorting.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_InsertBehaviorBefore.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable)
class UBTT_Camera_InsertBehaviorBefore : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackBehavior> BehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehavior>> InsertBeforeBehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting InsertBeforeBehaviorSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReuseBehaviorOnReactivate;
    
    UBTT_Camera_InsertBehaviorBefore();
};

