#pragma once
#include "CoreMinimal.h"
#include "PickupTool.h"
#include "Portkey_Object.generated.h"

class AActor;
class APortkey_Base;
class UStaticMesh;

UCLASS(Blueprintable)
class APortkey_Object : public APickupTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ActorOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* Portkey_Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APortkey_Base* PortkeyBase;
    
    APortkey_Object(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void EndTeleport();
    
};

