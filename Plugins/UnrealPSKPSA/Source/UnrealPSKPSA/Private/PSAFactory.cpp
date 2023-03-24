// Fill out your copyright notice in the Description page of Project Settings.


#include "PSAFactory.h"

#include "EditorAssetLibrary.h"
#include "PSAReader.h"
#include "SPSAImportOption.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/SkeletalMeshSocket.h"

#include "Misc/ScopedSlowTask.h"
#include "Rendering/SkeletalMeshLODImporterData.h"




UObject* UPSAFactory::Import(const FString Filename, UObject* Parent, const FName Name, const EObjectFlags Flags)
{
	auto Psa = PSAReader(Filename);
	if (!Psa.Read()) return nullptr;
	//
	bool ks = IsAutomatedImport();
	if (SettingsImporter->bInitialized == false)
	{
		TSharedPtr<SPSAImportOption> ImportOptionsWindow;
		TSharedPtr<SWindow> ParentWindow;
		if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
		{
			IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
			ParentWindow = MainFrame.GetParentWindow();
		}

		TSharedRef<SWindow> Window = SNew(SWindow)
			.Title(LOCTEXT("DatasmithImportSettingsTitle", "PSA Import Options"))
			.SizingRule(ESizingRule::Autosized);
		Window->SetContent
		(
			SAssignNew(ImportOptionsWindow, SPSAImportOption)
			.WidgetWindow(Window)
		);
		SettingsImporter = ImportOptionsWindow.Get()->Stun;
		FSlateApplication::Get().AddModalWindow(Window, ParentWindow, false);
		bImport = ImportOptionsWindow.Get()->ShouldImport();
		bImportAll = ImportOptionsWindow.Get()->ShouldImportAll();
		SettingsImporter->bInitialized = true;
	}

	auto AnimSequence = NewObject<UAnimSequence>(Parent, UAnimSequence::StaticClass(), Name, Flags);
	USkeleton* Skeleton = SettingsImporter->Skeleton;
	USkeletalMesh* SkeletalMesh = Skeleton->GetPreviewMesh();

	AnimSequence->SetSkeleton(Skeleton);
	AnimSequence->CreateAnimation(SkeletalMesh);
	auto MeshBones = Skeleton->GetReferenceSkeleton().GetRawRefBoneInfo();
	

	auto Info = Psa.AnimInfo;
	AnimSequence->SetRawNumberOfFrame(Info.NumRawFrames);
	AnimSequence->SequenceLength = Info.NumRawFrames/Info.AnimRate;
	
	FScopedSlowTask ImportTask(Psa.Bones.Num(), FText::FromString("Importing Anim"));
	ImportTask.MakeDialog(false);
	for (auto BoneIndex = 0; BoneIndex < Psa.Bones.Num(); BoneIndex++)
	{
		auto Bone = Psa.Bones[BoneIndex];
		auto BoneName = FName(Bone.Name);
		ImportTask.DefaultMessage = FText::FromString(FString::Printf(TEXT("Bone %s: %d/%d"), *BoneName.ToString(), BoneIndex+1, Psa.Bones.Num()));
		ImportTask.EnterProgressFrame();
		
		TArray<FVector> PositionalKeys;
		TArray<FQuat> RotationalKeys;
		TArray<FVector> ScaleKeys;
		for (auto Frame = 0; Frame < Info.NumRawFrames; Frame++)
		{
			auto KeyIndex = BoneIndex + Frame * Psa.Bones.Num();
			auto AnimKey = Psa.AnimKeys[KeyIndex];

			UE_LOG(LogTemp, Warning, TEXT(" Position %s"), *AnimKey.Position.ToString());
			PositionalKeys.Add(FVector(AnimKey.Position.X, -AnimKey.Position.Y, AnimKey.Position.Z));
			RotationalKeys.Add(FQuat(AnimKey.Orientation.X, -AnimKey.Orientation.Y, AnimKey.Orientation.Z, (BoneIndex == 0) ? -AnimKey.Orientation.W : AnimKey.Orientation.W).GetNormalized());
			ScaleKeys.Add(Psa.bHasScaleKeys ? Psa.ScaleKeys[KeyIndex].ScaleVector : FVector::OneVector);
			//ScaleKeys.Add(FVector::OneVector);
		}

		/*AnimSequence->AddBoneTrack(BoneName);
		AnimSequence.SetBoneTrackKeys(BoneName, PositionalKeys, RotationalKeys, ScaleKeys);*/
	}
	/*AnimSequence.RemoveBoneTracksMissingFromSkeleton(Skeleton);*/

	AnimSequence->Modify(true);
	AnimSequence->PostEditChange();
	FAssetRegistryModule::AssetCreated(AnimSequence);
	AnimSequence->MarkPackageDirty();

	for (TObjectIterator<USkeletalMeshComponent> Iter; Iter; ++Iter)
	{
		FComponentReregisterContext ReregisterContext(*Iter);
	}
	if (!bImportAll)
	{
		SettingsImporter->bInitialized = false;
	}
	return AnimSequence;
}


