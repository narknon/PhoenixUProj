#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackBehaviorSorting.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_PauseBehavior.generated.h"

class UCameraStackBehavior;

UCLASS(Blueprintable)
class UBTT_Camera_PauseBehavior : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackBehavior> BehaviorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackBehaviorSorting BehaviorSorting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FilterFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReturnImmediately;
    
    UBTT_Camera_PauseBehavior();
};

