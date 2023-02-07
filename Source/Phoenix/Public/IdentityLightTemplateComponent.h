#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "IdentityLightTemplateSettings.h"
#include "LightTemplateComponent.h"
#include "OnIdentityLightTemplateUpdateDelegate.h"
#include "IdentityLightTemplateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIdentityLightTemplateComponent : public ULightTemplateComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, FIdentityLightTemplateSettings> IdentityOverrides;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnIdentityLightTemplateUpdate OnIdentityUpdate;
    
    UIdentityLightTemplateComponent();
private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateIdentity(ESanctuaryIdentity PreviousIdentity, ESanctuaryIdentity CurrentIdentity, float BlendWeight);
    
};

