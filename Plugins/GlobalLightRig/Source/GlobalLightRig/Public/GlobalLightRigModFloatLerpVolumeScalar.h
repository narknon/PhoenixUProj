#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesScalarName.h"
#include "GlobalLightRigModFloatExternal.h"
#include "GlobalLightRigModFloatLerpVolumeScalar.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatLerpVolumeScalar : public UGlobalLightRigModFloatExternal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName Name;
    
    UGlobalLightRigModFloatLerpVolumeScalar();
};

