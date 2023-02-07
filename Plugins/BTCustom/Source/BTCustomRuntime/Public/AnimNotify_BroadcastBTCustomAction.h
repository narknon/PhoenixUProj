#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "BTCustomAction.h"
#include "EBTCustomActionType.h"
#include "AnimNotify_BroadcastBTCustomAction.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class BTCUSTOMRUNTIME_API UAnimNotify_BroadcastBTCustomAction : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction BTCustomAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBTCustomActionType::Type> BTCustomActionType;
    
    UAnimNotify_BroadcastBTCustomAction();
};

