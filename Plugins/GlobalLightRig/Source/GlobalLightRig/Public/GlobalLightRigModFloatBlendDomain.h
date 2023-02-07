#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModFloatExternal.h"
#include "GlobalLightRigModFloatBlendDomain.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatBlendDomain : public UGlobalLightRigModFloatExternal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* BlendDomain;
    
    UGlobalLightRigModFloatBlendDomain();
};

