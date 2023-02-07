#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponent.h"
#include "TransformedOverlandComponent.generated.h"

class AActor;
class UTransformationOverlandComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTransformedOverlandComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* OriginalActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTransformationOverlandComponent* OriginalComponent;
    
public:
    UTransformedOverlandComponent();
};

