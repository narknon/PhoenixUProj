#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "BoneClusterActor.generated.h"

class UPrimitiveComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ABoneClusterActor : public AActor {
    GENERATED_BODY()
public:
    ABoneClusterActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveStencilFromBones(TArray<UStaticMeshComponent*> Bones);
    
    UFUNCTION(BlueprintCallable)
    UPrimitiveComponent* GetClosestBoneComponent(const FVector& SourceLocation);
    
    UFUNCTION(BlueprintCallable)
    void ComputeBoneCloudCenterAndRadius();
    
};

