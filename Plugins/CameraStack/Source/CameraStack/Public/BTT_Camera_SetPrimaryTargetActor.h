#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "Templates/SubclassOf.h"
#include "BTT_Camera_SetPrimaryTargetActor.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable)
class UBTT_Camera_SetPrimaryTargetActor : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraStackSecondaryTargetGetter> TargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UBTT_Camera_SetPrimaryTargetActor();
};

