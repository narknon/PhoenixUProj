#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigInterfaceDefinition.generated.h"

class USceneRigInterfaceDefinition;
class USceneRigParameterDefinition;

UCLASS(Blueprintable, EditInlineNew)
class SCENERIG_API USceneRigInterfaceDefinition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USceneRigInterfaceDefinition*> InheritedParents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneRigParameterDefinition*> ParameterDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ExportPath;
    
    USceneRigInterfaceDefinition();
};

