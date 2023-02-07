#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackBehaviorSorting.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_DisableBehaviors.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable)
class UBTT_Camera_DisableBehaviors : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UCameraStackBehavior>> BehaviorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting BehaviorSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UBTT_Camera_DisableBehaviors();
};

