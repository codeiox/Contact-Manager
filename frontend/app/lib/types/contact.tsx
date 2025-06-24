// Type definition for contact form data sent to the backend
//
export type ContactData = {
  name: string;
  phone: string;
  email: string;
  tag?: string; // Optional tag field for categorization,
  // !Important: We may have to remove '?' to make it mandatory later if we want to group contacts by tag
};
