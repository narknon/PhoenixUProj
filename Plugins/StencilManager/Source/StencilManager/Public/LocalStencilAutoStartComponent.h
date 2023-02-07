#pragma once
#include "CoreMinimal.h"
#include "LocalStencilComponent.h"
#include "LocalStencilEffect.h"
#include "LocalStencilAutoStartComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilAutoStartComponent : public ULocalStencilComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffect AutoStartEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartOnBeginPlay;
    
    ULocalStencilAutoStartComponent();
    UFUNCTION(BlueprintCallable)
    bool LocalStencilEffectStart();
    
};

