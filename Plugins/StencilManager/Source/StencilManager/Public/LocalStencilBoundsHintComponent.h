#pragma once
#include "CoreMinimal.h"
#include "ELocalStencilBoundsHintMode.h"
#include "LocalStencilBoundsHintComponentBase.h"
#include "LocalStencilBoundsHintComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class STENCILMANAGER_API ULocalStencilBoundsHintComponent : public ULocalStencilBoundsHintComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELocalStencilBoundsHintMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ULocalStencilBoundsHintComponent();
};

