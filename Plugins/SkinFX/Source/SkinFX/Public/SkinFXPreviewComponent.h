#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SkinFXPreviewComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API USkinFXPreviewComponent : public USceneComponent {
    GENERATED_BODY()
public:
    USkinFXPreviewComponent();
    UFUNCTION(BlueprintCallable)
    void ResetEnvelope();
    
    UFUNCTION(BlueprintCallable)
    void ResetAll();
    
    UFUNCTION(BlueprintCallable)
    void ConstructPreview();
    
};

