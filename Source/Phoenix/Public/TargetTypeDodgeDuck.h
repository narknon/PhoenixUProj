#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "TargetTypeActor.h"
#include "UObject/NoExportTypes.h"
#include "TargetTypeDodgeDuck.generated.h"

class UTargetTracker;
class UTargetTypeBase;

UCLASS(Blueprintable)
class UTargetTypeDodgeDuck : public UTargetTypeActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector OriginalDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AngleOffset;
    
    UTargetTypeDodgeDuck();
    UFUNCTION(BlueprintCallable)
    static UTargetTypeBase* AddTarget_DodgeDuck(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, bool bUseCameraDirectionAlways);
    
};

