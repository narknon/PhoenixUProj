#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CogTargetSceneComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class COGNITION_API UCogTargetSceneComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UCogTargetSceneComponent();
private:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    static void CogTargetSceneComponent_DebugDraw(bool bInFlag);
    
};

