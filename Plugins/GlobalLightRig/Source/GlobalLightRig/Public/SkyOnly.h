#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "SkyAtmosphereSkyOnlyParameters.h"
#include "SkyOnly.generated.h"

class USkyAtmosphereComponent;
class USkyOnlyComponent;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API ASkyOnly : public AInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyOnlyComponent* SkyOnlyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDualDirectionalLights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkyAtmosphereComponent> CachedVisibleSkyAtmosphere;
    
public:
    ASkyOnly();
};

