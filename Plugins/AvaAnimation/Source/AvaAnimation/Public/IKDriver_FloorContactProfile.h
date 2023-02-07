#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCPMovementType.h"
#include "FCPSupportType.h"
#include "IKDriver_FloorContactProfileSettings.h"
#include "IKDriver_FloorContactProfile.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FIKDriver_FloorContactProfile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SlopeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpeedRange;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FCPSupportType SupportType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FCPMovementType MovementType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKDriver_FloorContactProfileSettings OverrideSettings;
    
    FIKDriver_FloorContactProfile();
};

