#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_Base.h"
#include "BTT_Camera_BlendToStackBase.generated.h"

class UCameraStackSettings;

UCLASS(Abstract, Blueprintable)
class UBTT_Camera_BlendToStackBase : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraStackSettings* StackSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReuseBehaviorOnReactivate;
    
    UBTT_Camera_BlendToStackBase();
};

