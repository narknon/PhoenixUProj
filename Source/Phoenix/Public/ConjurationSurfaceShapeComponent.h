#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "ConjurationSurfaceShapeComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UConjurationSurfaceShapeComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UConjurationSurfaceShapeComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumShapes() const;
    
    UFUNCTION(BlueprintCallable)
    void BuildShapeFromMeshes();
    
    UFUNCTION(BlueprintCallable)
    void BuildShapeFromCollision();
    
};

