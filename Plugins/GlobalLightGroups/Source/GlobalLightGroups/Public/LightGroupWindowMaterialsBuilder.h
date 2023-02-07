#pragma once
#include "CoreMinimal.h"
#include "LightGroupWindowMaterialsBuilder.generated.h"

class UMeshComponent;

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FLightGroupWindowMaterialsBuilder {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WindowGroupMaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LightGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> RelevantMaterialMeshes;
    
public:
    FLightGroupWindowMaterialsBuilder();
};

