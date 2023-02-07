#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puddle.generated.h"

class UPhoenixPhysicalMaterial;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class APuddle : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhoenixPhysicalMaterial* PhysMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
public:
    APuddle();
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
};

