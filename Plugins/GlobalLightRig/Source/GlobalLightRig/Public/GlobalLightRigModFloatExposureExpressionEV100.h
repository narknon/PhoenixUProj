#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModFloatExternal.h"
#include "GlobalLightRigModFloatExposureExpressionEV100.generated.h"

class UExposureExpressionsExposureValue;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatExposureExpressionEV100 : public UGlobalLightRigModFloatExternal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* ExposureExpression;
    
    UGlobalLightRigModFloatExposureExpressionEV100();
};

