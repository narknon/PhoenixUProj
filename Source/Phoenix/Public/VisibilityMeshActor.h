#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VisibilityMeshActor.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class PHOENIX_API AVisibilityMeshActor : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* VisibilityMesh;
    
public:
    AVisibilityMeshActor(const FObjectInitializer& ObjectInitializer);
};

